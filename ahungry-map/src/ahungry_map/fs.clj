(ns ahungry-map.fs)

;; Code related to parsing the files on disk.

;; (parse-map-lines "/home/mcarter/src/ahungry-map/res/maps/tutorialb.txt")
;; Line format is as such:
;; L 1186.0742, -2175.0840, 3.1260,  1215.0065, -2174.9312, 3.1260,  150, 0, 200
;; L -12.7163, 162.0129, 0.0020,  12.6721, 162.0129, 0.0020,  0, 0, 0
(defn parse-line [s]
  (->> (clojure.string/split s #",* +")
       (zipmap [:t :x1 :y1 :z1 :x2 :y2 :z2 :r :g :b :a :label])))

(defn parse-map-lines [file-name]
  (->> (clojure.string/split (slurp file-name) #"\r\n")
       (map parse-line)))

(defn get-resource-dir
  "Return the current resource (res/) directory."
  []
  "../res")

(defn get-zonelist
  "Get the zones in format such as:
  [{:label \"The Forgotten Halls\" :id \"fhalls\"}]"
  []
  (->> (clojure.string/split (slurp (str (get-resource-dir) "/zonelist.txt")) #"\n")
       (map #(clojure.string/split % #";"))
       (map #(zipmap [:label :id] %))))

(defn get-logs-in-dir
  "Get the logs in directory that appear to be an eq log."
  [dir]
  (let [directory (clojure.java.io/file dir)
        files (file-seq directory)]
    (filter #(re-matches #".*eqlog_.*\.txt$" (.toString %)) files)))

(defn get-newest-log-in-dir
  "Sort File results by last modification date."
  [dir]
  (->> (get-logs-in-dir dir)
       (sort (fn [a b] (> (.lastModified a) (.lastModified b))))
       first))

(defn get-content-of-newest-file []
  (slurp (get-newest-log-in-dir (str (get-resource-dir) "/log/"))))

(defn parse-zone-label-from-log-line [s]
  (last (re-find #".*You have entered (.*)\." s)))

(defn get-last-entered-zone []
  (let [content (get-content-of-newest-file)]
    (->> (clojure.string/split content #"\r\n")
         (filter #(re-matches #".*You have entered (.*)\." %))
         last
         parse-zone-label-from-log-line)))

(defn get-zone-id-from-label [label]
  (let [zl (get-zonelist)]
    (first (filter #(= (:label %) label) zl))))

(defn get-current-zone []
  (let [zone-label (get-last-entered-zone)
        zone-file-name (:id (get-zone-id-from-label zone-label))]
    zone-file-name))

(defn parse-position-from-log-line [s]
  (->>
   (re-find #".*Your Location is (.*?), (.*?), (.*)$" s)
   (zipmap [:_ :y :x :z])))

;; Your Location is 1192.57, -495.48, 3.41
(defn get-current-position []
  (let [content (get-content-of-newest-file)]
    (->> (clojure.string/split content #"\r\n")
         (filter #(re-matches #".*Your Location is.*" %))
         last
         parse-position-from-log-line)))

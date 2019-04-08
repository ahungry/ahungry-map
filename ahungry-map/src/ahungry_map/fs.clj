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

(defn get-zonelist []
  (->> (clojure.string/split (slurp (str (get-resource-dir) "/zonelist.txt")) #"\n")
       (map #(clojure.string/split % #";"))
       (map #(zipmap [:label :id] %))))

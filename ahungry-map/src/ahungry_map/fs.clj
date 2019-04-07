(ns ahungry-map.fs)

;; Code related to parsing the files on disk.

;; (parse-map-lines "/home/mcarter/src/ahungry-map/res/maps/tutorialb.txt")
;; Line format is as such:
;; L 1186.0742, -2175.0840, 3.1260,  1215.0065, -2174.9312, 3.1260,  150, 0, 200
(defn parse-line [s]
  (->> (clojure.string/split s #",* +")
      (zipmap [:t :x1 :x2 :y1 :y2 :z1 :z2 :r :g :b :a :label])))

(defn parse-map-lines [file-name]
  (->>
   (clojure.string/split (slurp file-name) #"\r\n")
   (map parse-line)))

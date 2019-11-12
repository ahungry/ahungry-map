(ns item-shop.db
  (:require
   [clojure.java.jdbc :as j]
   ))

(def masks-class
  [:war :clr :pal :rng :shd :dru :mnk :brd
   :rog :shm :nec :wiz :mag :enc])

(def class-map
  {:war 1 :clr 2 :pal 4 :rng 8
   :shd 16 :dru 32 :mnk 64 :brd 128
   :rog 256 :shm 512 :nec 1024 :wiz 2048
   :mag 4096 :enc 8192})

(def masks-slot
  [:hum :ear :head :face :ear :neck :shoulders
   :arms :back :wrist :wrist :range :hands :primary
   :secondary :fingers :fingers :chest :legs :feet
   :waist])

(def slot-map
  {:hum 1 :ear 2 :head 4 :face 8 :neck 32 :shoulders 64
   :arms 128 :back 256 :wrist 512 :range 2048 :hands 4096 :primary 8192
   :secondary 16384 :fingers 32768 :chest 131072 :legs 262144 :feet 524288
   :waist 1048576})

(def sort-options
  ["name" "ratio"])

(defn db []
  {:dbtype "sqlite"
   :dbname "../item-shop.db"})

(defn test-db []
  (j/query (db)
           ["SELECT COUNT(*) FROM eqItems"]))

(defn get-some []
  (j/query (db)
           ["SELECT name, nodrop, classes
FROM eqItems
WHERE 1=1
-- AND name LIKE ?
AND classes & 8
ORDER BY name
LIMIT 100000"
            ;; "%tolan%"
            ]))

(defn best-weapons-by-class [class]
  (let [mask (class class-map)]
    (j/query (db) ["SELECT name, damage, delay
, CAST(damage as float)/delay AS ratio
, nodrop, classes
FROM eqItems WHERE 1=1
AND classes & ?
ORDER BY
CAST(damage as float)/delay
DESC LIMIT 10"
                   mask])))

(defn get-items []
  (map :name (get-some)))

(defn maybe-class-mask [class]
  (if class
    (class class-map)
    65535))

(defn maybe-slot-mask [slot]
  (if slot
    (slot slot-map)
    (reduce + (vals slot-map))))

(defn maybe-limit [limit]
  (or limit 10))

(defn maybe-sort [sort]
  (let [msort (or sort "name")]
    (case msort
      "ratio" "CAST(damage as float)/delay"
      msort)))

(defn maybe-no-drop [no-drop]
  (if no-drop
    " AND nodrop = 0 "
    ""))

(defn maybe-drop [drop]
  (if drop
    " AND nodrop = 1 "
    ""))

(defn maybe-has-proc [has-proc]
  (if has-proc
    " AND proceffect > 0 "
    ""))

(defn maybe-has-click [has-click] (if has-click " AND clickeffect > 0 " ""))
(defn maybe-has-worn [has-worn] (if has-worn " AND worneffect > 0 " ""))

(defn maybe-is-weapon [is-weapon]
  (if is-weapon
    " AND damage > 0 "
    ""))

(defn get-some-from-params [{:keys [class slot limit sort no-drop drop
                                    has-proc has-click has-worn
                                    is-weapon]}]
  (let [mask (maybe-class-mask class)
        mask-slot (maybe-slot-mask slot)
        sort (maybe-sort sort)
        limit (maybe-limit limit)]
    (j/query
     (db)
     [(format "SELECT e.name as name, damage, delay
, CAST(damage as float)/delay AS ratio
, nodrop, classes
, p.name as proc_name
, c.name as click_name
, w.name as worn_name
FROM eqItems e
LEFT JOIN eqSpells p ON e.proceffect = p.id
LEFT JOIN eqSpells c ON e.clickeffect = c.id
LEFT JOIN eqSpells w ON e.worneffect = w.id
WHERE 1=1
%s
%s
%s
%s
%s
%s
AND classes & ?
AND slots & ?
ORDER BY
%s DESC
LIMIT ?"
              (maybe-no-drop no-drop)
              (maybe-drop drop)
              (maybe-has-proc has-proc)
              (maybe-has-click has-click)
              (maybe-has-worn has-worn)
              (maybe-is-weapon is-weapon)
              sort)
      mask
      mask-slot
      limit])))

(defn get-items-from-params [params]
  (let [rows (get-some-from-params params)]
    (map str rows)))

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
LIMIT 10"
            ;; "%tolan%"
            ]))

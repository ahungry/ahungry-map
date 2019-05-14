(ns item-shop.db
  (:require
   [clojure.java.jdbc :as j]
   ))

(defn db []
  {:dbtype "sqlite"
   :dbname "../item-shop.db"})

(defn test-db []
  (j/query (db)
           ["SELECT COUNT(*) FROM eqItems"]))

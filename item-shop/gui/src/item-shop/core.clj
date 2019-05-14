;; https://github.com/cljfx/cljfx
;; https://clojure.org/guides/deps_and_cli
(ns item-shop.core
  (:require
   [cljfx.api :as fx]
   [clojure.java.jdbc :as j]
   ))

(defn db []
  {:dbtype "sqlite"
   :dbname "../item-shop.db"})

(defn test-db []
  (j/query (db)
           ["SELECT COUNT(*) FROM eqItems"]))

(defn -main [& args]
  (fx/on-fx-thread
   (fx/create-component
    {:fx/type :stage
     :showing true
     :title "Cljfx example"
     :width 300
     :height 100
     :scene {:fx/type :scene
             :root {:fx/type :v-box
                    :alignment :center
                    :children [{:fx/type :label
                                :text "Hello world"}]}}})))

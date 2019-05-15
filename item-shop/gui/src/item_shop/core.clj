;; https://github.com/cljfx/cljfx
;; https://clojure.org/guides/deps_and_cli
;; https://github.com/clojure/tools.deps.alpha/wiki/Tools
(ns item-shop.core
  (:require
   [item-shop.db :as db]
   [item-shop.gui :as gui]
   ))

(defn sanity []
  (db/db))

(defn -main [& args]
  (gui/set-items (db/get-items))
  (gui/main))

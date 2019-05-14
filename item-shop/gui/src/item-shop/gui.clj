;; https://github.com/cljfx/cljfx
;; https://clojure.org/guides/deps_and_cli
;; https://github.com/clojure/tools.deps.alpha/wiki/Tools
;; https://github.com/cljfx/cljfx/blob/30a8c71d5bab559a733e4bb19d1412ef1227b0f5/examples/e16_cell_factories.clj
(ns item-shop.gui
  (:require
   [cljfx.api :as fx]
   ))

(defn main [& args]
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
                    :children
                    [{:fx/type :label
                      :text "Hello world"}
                     {:fx/type :list-view
                      :cell-factory (fn [i]
                                      (let [color (format "#%03x" i)]
                                        {:style {:-fx-backround-color color}
                                         :text color}))
                      :items (range 16r1000)
                      ;; :items ["one" :two]
                      }]}}})))

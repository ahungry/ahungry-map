;; https://github.com/cljfx/cljfx
;; https://clojure.org/guides/deps_and_cli
;; https://github.com/clojure/tools.deps.alpha/wiki/Tools
;; https://github.com/cljfx/cljfx/blob/30a8c71d5bab559a733e4bb19d1412ef1227b0f5/examples/e16_cell_factories.clj
(ns item-shop.gui
  (:require
   [cljfx.api :as fx]
   )
  (:import
   [javafx.scene.input KeyCode KeyEvent]
   ))

(def *state (atom {}))

;; :fx/event is the id in the list that was clicked
(defn map-event-handler [event]
  (prn "got an event!" event)
  (case (:event/type event)
    ;; ::set-done (swap! *state assoc-in [:by-id (:id event) :done] (:fx/event event))
    ::set-done (reset! *state {:full event :event (:fx/event event)})
    ))

(defn root [{:keys [by-id typed-text]}]
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
                   {:fx/type :button
                    ;; :on-action {:event/type ::set-done :id 3}
                    :on-action (fn [_] (reset! *state "You clicked me!"))
                    :text "Click me"}
                   {:fx/type :list-view
                    ;; :on-selected-item-changed (fn [_] (reset! *state "Blub"))
                    :on-selected-item-changed {:event/type ::set-done :id 3}
                    :cell-factory (fn [i]
                                    (let [color (format "#%03x" i)]
                                      {:style {:-fx-background-color color}
                                       ;; :on-selected-clicked {:event/type ::set-done :id 3}
                                       :text color}))
                    :items (range 16r10)
                    ;; :items ["one" :two]
                    }]}}})

(def renderer
  (fx/create-renderer
   :middleware (fx/wrap-map-desc assoc :fx/type root)
   :opts {:fx.opt/map-event-handler map-event-handler}))

(defn xmain [& args]
  (fx/mount-renderer *state renderer))

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
                                        {:style {:-fx-background-color color}
                                         :text color}))
                      :items (range 16r100000)
                      ;; :items ["one" :two]
                      }]}}})))

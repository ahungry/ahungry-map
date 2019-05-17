;; https://github.com/cljfx/cljfx
;; https://clojure.org/guides/deps_and_cli
;; https://github.com/clojure/tools.deps.alpha/wiki/Tools
;; https://github.com/cljfx/cljfx/blob/30a8c71d5bab559a733e4bb19d1412ef1227b0f5/examples/e16_cell_factories.clj
(ns item-shop.gui
  (:require
   [cljfx.api :as fx]
   [item-shop.db :as db]
   )
  (:import
   [javafx.scene.input KeyCode KeyEvent]
   ))

(def *state (atom {:items [:a :b :c]}))

(defn set-items [items]
  (swap! *state assoc-in [:items] items))

(defn set-items-from-state []
  (let [class-selected (:class-selected @*state)
        sort-selected (:sort-selected @*state)
        no-drop-selected (:no-drop-selected @*state)
        drop-selected (:drop-selected @*state)
        proc-selected (:proc-selected @*state)
        click-selected (:click-selected @*state)
        worn-selected (:worn-selected @*state)
        weapon-selected (:weapon-selected @*state)]
    (set-items (db/get-items-from-params
                {:limit 10e6
                 :class class-selected
                 :no-drop no-drop-selected
                 :drop drop-selected
                 :has-proc proc-selected
                 :has-click click-selected
                 :has-worn worn-selected
                 :is-weapon weapon-selected
                 :sort sort-selected}))))

;; :fx/event is the id in the list that was clicked (actually, the list label)
(defn map-event-handler [event]
  (prn "got an event!" event)
  (case (:event/type event)
    ;; ::set-done (swap! *state assoc-in [:by-id (:id event) :done] (:fx/event event))
    ;; ::set-done (reset! *state {:full event :event (:fx/event event)})
    ::set-item (swap! *state assoc-in [:item-selected] (:fx/event event))
    ::text-changed (swap! *state assoc-in [:filter] (:fx/event event))
    ::class-change (do (swap! *state assoc-in [:class-selected] (:fx/event event))
                       (set-items-from-state))
    ::sort-change (do (swap! *state assoc-in [:sort-selected] (:fx/event event))
                       (set-items-from-state))
    ::no-drop-change (do (swap! *state assoc-in [:no-drop-selected] (:fx/event event))
                       (set-items-from-state))
    ::drop-change (do (swap! *state assoc-in [:drop-selected] (:fx/event event))
                       (set-items-from-state))
    ::proc-change (do (swap! *state assoc-in [:proc-selected] (:fx/event event))
                       (set-items-from-state))
    ::click-change (do (swap! *state assoc-in [:click-selected] (:fx/event event))
                       (set-items-from-state))
    ::worn-change (do (swap! *state assoc-in [:worn-selected] (:fx/event event))
                       (set-items-from-state))
    ::weapon-change (do (swap! *state assoc-in [:weapon-selected] (:fx/event event))
                       (set-items-from-state))
    ))

(defn text-input [{:keys [text]}]
  {:fx/type :text-area
   :style {:-fx-font-family "monospace"}
   :text text
   :on-text-changed {:event/type ::text-changed}})

(defn sort-input [_]
  {:fx/type :list-view
   :max-height 60
   :on-selected-item-changed {:event/type ::sort-change}
   :cell-factory
   (fn [i]
     (let [name (str i)]
       {:text name}))
   :items db/sort-options})

(defn class-input [_]
  {:fx/type :list-view
   :max-height 60
   :on-selected-item-changed {:event/type ::class-change}
   :cell-factory
   (fn [i]
     (let [name (str i)]
       {:text name}))
   :items db/masks-class})

(defn checkbox-input [{:keys [text event-type]}]
  {:fx/type :h-box
   :spacing 5
   :padding 5
   :children [{:fx/type :label :text text}
              {:fx/type :check-box
               :on-selected-changed {:event/type event-type}}]})

(defn filter-items [reg items]
  (filter #(re-find reg %) items))

(defn get-filtered-items []
  (let [items (:items @*state)
        filt (:filter @*state)
        reg (re-pattern (str "(?i)" filt))]
    (filter-items reg items)))


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
                  [
                   {:fx/type :h-box
                    :children
                    [{:fx/type text-input :text (:filter @*state)}]}
                   {:fx/type checkbox-input :text "No Drop?" :event-type ::no-drop-change}
                   {:fx/type checkbox-input :text "Droppable?" :event-type ::drop-change}
                   {:fx/type checkbox-input :text "Has Proc?" :event-type ::proc-change}
                   {:fx/type checkbox-input :text "Has Click?" :event-type ::click-change}
                   {:fx/type checkbox-input :text "Has Worn?" :event-type ::worn-change}
                   {:fx/type checkbox-input :text "Is Weapon?" :event-type ::weapon-change}
                   {:fx/type :grid-pane
                    :children
                    [
                     {:fx/type :h-box
                      :grid-pane/column 0
                      :grid-pane/row 0
                      :children
                      [
                       {:fx/type class-input}]}
                     {:fx/type :h-box
                      :grid-pane/column 1
                      :grid-pane/row 0
                      :children
                      [
                       {:fx/type sort-input}]}
                     ]}
                   {:fx/type :label
                    :text (str "Selected: " (:item-selected @*state))
                    ;; :text "Hello world"
                    }
                   {:fx/type :button
                    ;; :on-action {:event/type ::set-done :id 3}
                    :on-action (fn [_]
                                 (prn "Clicked the button"))
                    :text "Click me"}
                   {:fx/type :list-view
                    ;; :on-selected-item-changed (fn [_] (reset! *state "Blub"))
                    :on-selected-item-changed {:event/type ::set-item}
                    :cell-factory
                    ;; (fn [i]
                    ;;   (let [color (format "#%03x" i)]
                    ;;     {:style {:-fx-background-color color}
                    ;;      :text color}))
                    ;; :items (range 16r10)
                    (fn [i]
                      (let [name (str i)]
                        {
                         ;; :style {:-fx-background-color "#999"}
                         :text name}))
                    :items (get-filtered-items)
                    ;; :items (:items @*state)
                    ;; :items ["one" :two]
                    }]}}})

(def renderer
  (fx/create-renderer
   :middleware (fx/wrap-map-desc assoc :fx/type root)
   :opts {:fx.opt/map-event-handler map-event-handler}))

(defn main [& args]
  (set-items-from-state)
  (fx/mount-renderer *state renderer))

;; (defn main [& args]
;;   (fx/on-fx-thread
;;    (fx/create-component
;;     {:fx/type :stage
;;      :showing true
;;      :title "Cljfx example"
;;      :width 300
;;      :height 100
;;      :scene {:fx/type :scene
;;              :root {:fx/type :v-box
;;                     :alignment :center
;;                     :children
;;                     [{:fx/type :label
;;                       :text "Hello world"}
;;                      {:fx/type :list-view
;;                       :cell-factory (fn [i]
;;                                       (let [color (format "#%03x" i)]
;;                                         {:style {:-fx-background-color color}
;;                                          :text color}))
;;                       :items (range 16r100000)
;;                       ;; :items ["one" :two]
;;                       }]}}})))

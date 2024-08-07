(ns ahungry-map.core
  (:require
   [ahungry-map.fs :as afs]
   [quil.core :as q]
   [quil.middleware :as m]))

;; Some are in brewall (butcher)
;; Some are in the dist
(def world-map
  (atom
   (afs/parse-map-lines
    (str
     ;; "/home/mcarter/Downloads/brewall/"
     "/home/mcarter/src/ahungry-map/res/maps/"
     (str (afs/get-current-zone) ".txt")
     ;; "butcher.txt"
     ;; "ecommons.txt"
     ))))

(def player-position
  (atom
   (afs/get-current-position)))

(defn update-player-position []
  (reset! player-position
          (afs/get-current-position))
  (Thread/sleep 2000))

(defn update-zone []
  (reset! world-map
          (afs/parse-map-lines
           (str "/home/mcarter/src/ahungry-map/res/maps/" (afs/get-current-zone) ".txt")))
  (Thread/sleep 5000))

(def update-player-position-future (atom nil))
(def update-zone-future (atom nil))

(defn run-threads []
  (reset! update-player-position-future (future (while true (do (update-player-position)))))
  (reset! update-zone-future (future (while true (do (update-zone))))))

(defn setup []
  ; Set frame rate to 1 frames per second.
  (q/frame-rate 15)
  ; Set color mode to HSB (HSV) instead of default RGB.
  (q/color-mode :rgb)
  ;; (q/color-mode :hsb)
  ; setup function returns initial state. It contains
  ; circle color and position.
  {:color 0
   :angle 0
   :offset-y 0
   :offset-x 0
   :scale 10
   :cycle 100
   :x 0
   :y 0})

(defn update-state [state]
  ; Update sketch state by changing circle color and position.
  (conj
   state
   {:color (mod (+ (:color state) 0.7) 255)
    :angle (+ (:angle state) 0.1)
    :world-map @world-map
    :x (read-string (:x @player-position))
    :y (read-string (:y @player-position))}))

(defn draw-state [state]
  ;; Clear the sketch by filling it with light-grey color.
  (q/background 215 215 150)

  ;; Set circle color.
  (q/fill (:color state) 255 255)

  (q/with-translation [(+ (/ (q/width) 2) (:offset-x state))
                       (+ (/ (q/height) 2) (:offset-y state))]
    (q/ellipse 0 0 10 10)
    (let [scale (:scale state)]
      (q/with-translation [(+ 0 (/ (:x state) scale))
                           (+ 0 (/ (:y state) scale))]
        ;; Draw map
        (q/fill 100 55 0)
        (q/stroke 150 100)
        (doall (map (fn [{:keys [t x1 x2 y1 y2 g]}]
                      ;; Draw a basic line segment
                      (when (= "L" t)
                        (q/line (/ (read-string x1) scale)
                                (/ (read-string y1) scale)
                                (/ (read-string x2) scale)
                                (/ (read-string y2) scale)))
                      (when (= "P" t)
                        (q/text (str g)
                                (/ (read-string x1) scale)
                                (/ (read-string y1) scale)))
                      )
                    (:world-map state)
                    )))))

  ;; Calculate x and y coordinates of the circle.
  ;; (let [angle (:angle state)
  ;;       x (* 150 (q/cos angle))
  ;;       y (* 150 (q/sin angle))]
  ;;                                       ; Move origin point to the center of the sketch.
  ;;   (q/with-translation [(/ (q/width) 2)
  ;;                        (/ (q/height) 2)]

  ;;     ;; Draw the circle.
  ;;     (q/ellipse x y 100 100)))
  )

(defn hmm []
  (do (map (fn [{:keys [x1 x2 y1 y2]}]
             (prn x1 x2 y1 y2)
             (vector (read-string x1)
                     (read-string y1)
                     (read-string x2)
                     (read-string y2))) (take 3 @world-map))))

(defn -main [& args]
  (q/defsketch ahungry-map
    :title "EQ Map"
    :size [700 500]
                                        ; setup function called only once, during sketch initialization.
    :setup setup
                                        ; update-state is called on each iteration before draw-state.
    :update update-state
    :draw draw-state
    :key-pressed
    (fn [state {:keys [key _key-code]}]
      (case key
        (:o) (conj state {:scale (* (:scale state) 2)})
        (:i) (conj state {:scale (/ (:scale state) 2)})
        (:r) (conj state {:offset-x 0 :offset-y 0 :scale 10})
        (:w) (conj state {:offset-y (+ (:offset-y state) 100)})
        (:s) (conj state {:offset-y (- (:offset-y state) 100)})
        (:a) (conj state {:offset-x (+ (:offset-x state) 100)})
        (:d) (conj state {:offset-x (- (:offset-x state) 100)})
        (:k) (conj state {:offset-y (+ (:offset-y state) 100)})
        (:j) (conj state {:offset-y (- (:offset-y state) 100)})
        (:h) (conj state {:offset-x (+ (:offset-x state) 100)})
        (:l) (conj state {:offset-x (- (:offset-x state) 100)})
        (:up) (conj state {:offset-y (+ (:offset-y state) 100)})
        (:down) (conj state {:offset-y (- (:offset-y state) 100)})
        (:left) (conj state {:offset-x (+ (:offset-x state) 100)})
        (:right) (conj state {:offset-x (- (:offset-x state) 100)})
        state))
    :features [:keep-on-top]
                                        ; This sketch uses functional-mode middleware.
                                        ; Check quil wiki for more info about middlewares and particularly
                                        ; fun-mode.
    :middleware [m/fun-mode]))

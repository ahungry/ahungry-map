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

(def scale (atom 10))
(def player-position
  (atom
   (afs/get-current-position)))

(defn update-positions []
  (reset! world-map
          (afs/parse-map-lines
           (str "/home/mcarter/src/ahungry-map/res/maps/" (afs/get-current-zone) ".txt")))
  (reset! player-position
          (afs/get-current-position))
  (Thread/sleep 1000))

(defn run-threads []
  (future (while true (do (update-positions)))))

(defn process-key [rk]
  (case (str rk)
    "o" (swap! scale * 2)
    "i" (swap! scale / 2)
    nil
    ;; (prn "Unmapped key" rk)
    ))

(defn setup []
  ; Set frame rate to 1 frames per second.
  (q/frame-rate 1)
  ; Set color mode to HSB (HSV) instead of default RGB.
  (q/color-mode :rgb)
  ;; (q/color-mode :hsb)
  ; setup function returns initial state. It contains
  ; circle color and position.
  {:color 0
   :angle 0
   :scale 10
   :cycle 100
   :x 0
   :y 0})

(defn update-state [state]
  ; Update sketch state by changing circle color and position.
  {:color (mod (+ (:color state) 0.7) 255)
   :angle (+ (:angle state) 0.1)
   :world-map @world-map
   :scale @scale
   :x (read-string (:x @player-position))
   :y (read-string (:y @player-position))})

(defn draw-state [state]
  ;; Clear the sketch by filling it with light-grey color.
  (q/background 215 215 150)

  (when (q/key-pressed?)
    (process-key (q/raw-key)))

  ;; Set circle color.
  (q/fill (:color state) 255 255)

  (q/with-translation [(/ (q/width) 2)
                       (/ (q/height) 2)]
    (q/ellipse 0 0 10 10)
    (let [scale (:scale state)]
      (q/with-translation [(+ 0 (/ (:x state) scale))
                           (+ 0 (/ (:y state) scale))]
        ;; Draw map
        (q/fill 100 255 200)
        (q/stroke 100)
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
    :title "You spin my circle right round"
    :size [900 900]
                                        ; setup function called only once, during sketch initialization.
    :setup setup
                                        ; update-state is called on each iteration before draw-state.
    :update update-state
    :draw draw-state
    :features [:keep-on-top]
                                        ; This sketch uses functional-mode middleware.
                                        ; Check quil wiki for more info about middlewares and particularly
                                        ; fun-mode.
    :middleware [m/fun-mode]))

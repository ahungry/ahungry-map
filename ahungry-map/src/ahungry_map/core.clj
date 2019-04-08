(ns ahungry-map.core
  (:require
   [ahungry-map.fs :as afs]
   [quil.core :as q]
   [quil.middleware :as m]))

(def world-map
  (afs/parse-map-lines
   (str
    "/home/mcarter/src/ahungry-map/res/maps/"
    (afs/get-current-map-file) ".txt")))

(defn setup []
  ; Set frame rate to 1 frames per second.
  (q/frame-rate 1)
  ; Set color mode to HSB (HSV) instead of default RGB.
  (q/color-mode :hsb)
  ; setup function returns initial state. It contains
  ; circle color and position.
  {:color 0
   :angle 0})

(defn update-state [state]
  ; Update sketch state by changing circle color and position.
  {:color (mod (+ (:color state) 0.7) 255)
   :angle (+ (:angle state) 0.1)})

(defn draw-state [state]
  ;; Clear the sketch by filling it with light-grey color.
  (q/background 240)
  ;; Set circle color.
  (q/fill (:color state) 255 255)

  (q/with-translation [500 500]
    ;; Draw map
    (doall (map (fn [{:keys [t x1 x2 y1 y2]}]
                  (when (= "L" t)
                    (q/line (/ (read-string x1) 10)
                            (/ (read-string y1) 10)
                            (/ (read-string x2) 10)
                            (/ (read-string y2) 10))))
                (take 3000 world-map))))

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
                     (read-string y2))) (take 3 world-map))))

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

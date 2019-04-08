(ns ahungry-map.fs-test
  (:require
   [ahungry-map.fs :as afs]
   [clojure.test :as t :refer [deftest testing is run-tests]]
   ))

(deftest parse-line []
  (testing "Ensure line parse is as expected."
    (let [parsed (afs/parse-line "L 1186.0742, -2175.0840, 3.1260,  1215.0065, -2174.9312, 3.1260,  150, 0, 200")]
      (is (= "L" (:t parsed)))
      (is (= "1186.0742" (:x1 parsed)))
      (is (= "-2175.0840" (:y1 parsed)))
      (is (= "3.1260" (:z1 parsed)))
      (is (= "1215.0065" (:x2 parsed)))
      (is (= "-2174.9312" (:y2 parsed)))
      (is (= "3.1260" (:z2 parsed)))
      (is (= "150" (:r parsed)))
      (is (= "0" (:g parsed)))
      (is (= "200" (:b parsed)))
      )))

(run-tests)

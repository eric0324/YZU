#lang racket

(define (sumex lst)
      (let ((min (car lst)) (max (car lst))) ;let min and max
        (define (find lst) ;find minimum and maximum
          (if (null? lst)
              (list min max)
              (let ((c (car lst)))
                (when (< c min) (set! min c))
                (when (> c max) (set! max c))
                (find (cdr lst)))))
        (find lst)
        (+ min max))) ;return answer

;(sumex`(10 20 5 7 9 50))
;(sumex`(5 4 3 2 1))
;(sumex`(9 99 19 59 79 39))
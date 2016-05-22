#lang racket

(define (replacetop list old new)
 (cond
  ((null? list) '())
  ((eq? (car list) old) ;check element is equal?
   (cons new (replacetop (cdr list) old new)))  ;replace new element
  (else
   (cons (car list) (replacetop (cdr list) old new))))) ;cons old element

;(replacetop `(A B C A C A) `A `K)
;(replacetop `(domestic cat (Asian cat) wild cat hybrid cat) `cat `dog)
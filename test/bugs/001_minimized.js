/*
 * ### Test Summary November 15, 2011 at 21:29:52
 * ### Time Taken: Average 316 ms.  Best KJS 12 ms. Worst Rhino 778 ms).
 *
 * SpiderMonkey: (1, 5.458913070090713e+27)
 * Rhino: (1, 5.458913070090713e+27)
 * V8: (1, 5.458913070090714e+27)
 * KJS: (1, 5.458913070090714e+27)
 * Narcissus: (1, 5.458913070090713e+27)
 */
var a = 1435238133*1889579895*2012875688;
var b = 1435238133*(1889579895*2012875688);
(function () {
   print(a); print(" ");
   print(b); print(" ");

   print(a.toString(2));
   print(b.toString(2));
})();

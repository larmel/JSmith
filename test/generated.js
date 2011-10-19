/*	JSmith	*/
var x = 1260
function foo() {x = 1;

return x++; };
(function main(){ hash = foo(); print(hash); return 0; })();
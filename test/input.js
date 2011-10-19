var foo = 4;

function func1(a, b) {
    foo = a = b | 10;
    return b == 2 && a;
}


(function main() {
    func1(10, 44);
    
    
    hash = "" + foo;
    print(hash);
    return 0;
})();

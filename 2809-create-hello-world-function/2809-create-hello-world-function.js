/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        const str = "Hello World";
        return str;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
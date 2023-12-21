/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    const myMap = new Map();
    myMap.set("(");
    myMap.set("{");
    myMap.set("[");

    const myMap2 = {
        ")": "(",
        "}": "{",
        "]": "["
    };

    const openingBraces = [];
    if (s.length === 1) return false;
    if (s[0] === ")" || s[0] === "}" || s[0] === "]" && !openingBraces.length) return false;

    for (let i = 0; i < s.length; i++) {
        if (myMap.has(s[i])) openingBraces.push(s[i]);
        if (myMap2[s[i]]) {
            const isAMatch = myMap2[s[i]] === openingBraces.at(-1)
            if (!isAMatch) return false;
            openingBraces.pop();
        }
    }

    if (openingBraces.length === 0) return true;
    return false;
};
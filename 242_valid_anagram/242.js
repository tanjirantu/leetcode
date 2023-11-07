/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */


var isAnagram = function (s, t) {
    let myMap = {};

    let count = 0;
    const len = s.length;
    if (len !== t.length) return false;

    myMap[s[0]] = 0;
    for (let i = 0; i < len; i++) {
        if (myMap[s[i]]) myMap[s[i]]++;
        else myMap[s[i]] = 1;
    }

    let myMap2 = {};
    myMap2[t[0]] = 0;
    for (let i = 0; i < len; i++) {
        if (myMap2[t[i]]) myMap2[t[i]]++;
        else myMap2[t[i]] = 1;
    }

    for (let i = 0; i < len; i++) {
        if (myMap[s[i]] == myMap2[s[i]]) count++;
    }

    if (count === len) return true;
    return false;
};

console.log(isAnagram("anagram", "nagaram"));
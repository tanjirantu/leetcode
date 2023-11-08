/**
 * @param {string[]} strs
 * @return {string[][]}
 */

var groupAnagrams = function (strs) {
    const myMap = {};

    for (let i = 0; i < strs.length; ++i) {
        const source = strs[i].split("").sort().join("");

        if (!myMap[source]) myMap[source] = [strs[i]]
        else myMap[source].push(strs[i])
    }

    return Object.values(myMap);
};
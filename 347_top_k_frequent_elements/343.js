/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */

var topKFrequent = function (nums, k) {
    const myMap = new Map();

    const arrLen = nums.length;
    const myArr = [];

    for (let i = 0; i <= arrLen; ++i) {
        if (i > 0) myArr[i] = [];
        if (i < arrLen) {
            if (myMap.has(nums[i])) {
                let value = myMap.get(nums[i]);
                myMap.set(nums[i], ++value);
            } else {
                myMap.set(nums[i], 1);
            }
        }
    }

    for (const [key, value] of myMap) {
        myArr[value].push(key)
    }

    const res = [];
    for (let i = myArr.length - 1; i >= 1; --i) {
        if (myArr[i].length) res.push(...myArr[i]);
        if (res.length === k) return res;
    }

    return res;
};
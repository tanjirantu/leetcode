/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function (grid) {
    let count = 0;
    for (let i = 0; i < grid.length; i++) {
        if (grid[i][0] < 0) {
            count += grid[i].length;
            continue;
        }
        let lo = 0;
        let hi = grid[i].length - 1;
        while (lo <= hi) {
            let mid = Math.floor((lo + hi) / 2);
            if (grid[i][mid] >= 0) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        count += grid[i].length - lo;
    }
    return count;
};

const count = countNegatives([[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]);
console.log({ count })
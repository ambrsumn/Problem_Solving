/**
 * @param {number[]} nums
 * @return {number}
 */
var minElement = function (nums) {
let ans = 1e9;
    nums.forEach((num) => {
        let str = num.toString();
        let sum = 0;
        str.split('').forEach((ch) => {
            sum += Number(ch);
        })

        ans = Math.min(ans, sum);
    });

    return ans;
};        
/**
 * @param {number[]} nums
 * @return {string}
 */

const comparator = function(a, b)
{
    let stringAFirst = a+b;
    let stringBFirst = b+a;

    return stringAFirst <= stringBFirst ? 1 : -1;
}

var largestNumber = function(nums) {

    let arr = [];
    for(const it of nums)
    {
        arr.push(it.toString());
    }

    arr.sort(comparator);
    if (arr[0] === "0") return "0";
    let ans = "";

    for(const it of arr)ans += it;

    return ans;
    
};
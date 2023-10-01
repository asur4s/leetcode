function getMinNum(nums: number[], a: number, b: number) {
    let minNum = Infinity
    for (let i = a; i < b; i++) {
        if (minNum > nums[i]) {
            minNum = nums[i]
        }
    }
    return minNum
}

function maximumTripletValue(nums: number[]): number {
    let maxVal = -Infinity
    let flag = false

    for (let i = 0; i < nums.length; i++) {
        for (let k = i + 2; k < nums.length; k++) {
            let minNum = getMinNum(nums, i, k)
            if (nums[i] === minNum) {
                continue
            }

            let val = (nums[i] - minNum) * nums[k];
            if (val > 0) {
                flag = true
            }
            if (val > maxVal) {
                maxVal = val
            }
        }
    }
    return flag ? maxVal : 0;
};


/**
 * 1. 如果 val 等于 minVal，该怎么取？
 * 前一个还是后一个？取前一个和后一个都一样，取前一个还能减少计算
 */

/**
 * 2. 如何缩小计算范围？找规律，看哪些方法可以减少计算量。
 * (1）j 使用最小值代替
 * (2) nums[j] - minNum 等于 0 时，不计算。
 * (3) k 的值采用最接近的值代替!!!不可行
 */

/**
 * 3. 可以排序吗？
 * 不可以，因为 i, j, k 有顺序。
 */

let res: any;

res = maximumTripletValue([1, 10, 3, 4, 19])
console.assert(res === 133, "ERROR: " + res)
console.log("=============================");

res = maximumTripletValue([12, 6, 1, 2, 7])
console.assert(res === 77, "ERROR: " + res)
console.log("=============================");

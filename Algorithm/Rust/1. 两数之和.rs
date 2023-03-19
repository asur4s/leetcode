impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut res = Vec::new();
        for (i, num1) in nums.iter().enumerate() {
            for (j, num2) in nums.iter().enumerate() {
                if i == j {
                    continue;
                }
                if num1 + num2 == target {
                    res = vec![i as i32, j as i32];
                }
            }
        }
        res
    }
}

use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut res = Vec::new();
        let mut map = HashMap::new();
        for (i, num) in nums.iter().enumerate() {
            let i = i as i32;
            let target_num = target - num;
            if let Some(target_index) = map.get(&target_num) {
                res = vec![i, *target_index];
                break;
            } else {
                map.insert(num, i);
            }
        }
        res
    }
}

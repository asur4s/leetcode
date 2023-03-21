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

pub struct Solution {}

fn main() {
    #[allow(clippy::single_element_loop)]
    for test_case in [
        (vec![2, 7, 11, 15], 9, vec![0, 1]),
        (vec![3, 2, 4], 6, vec![1, 2]),
        (vec![3, 3], 6, vec![0, 1]),
    ] {
        let nums = test_case.0.to_vec();
        let target = test_case.1;
        let mut res = Solution::two_sum(nums, target);

        let mut target_res = test_case.2.to_vec();
        res.sort();
        target_res.sort();
        assert_eq!(res, target_res, "args: {:?}", test_case);
    }
}

/**
* Problem Link: https://leetcode.com/problems/01-matrix/description/
**/

//Approach 1: TC: O(N * M), SC: O(N * M)
func updateMatrix(mat [][]int) [][]int {
	res := make([][]int, len(mat))
	for i := 0; i < len(mat); i++ {
		res[i] = make([]int, len(mat[i]))
	}
	queue := []string{}
	for row := range len(mat) {
		for col := range len(mat[row]) {
			if mat[row][col] == 0 {
				res[row][col] = 0
				queue = append(queue, strconv.Itoa(row) + ":" + strconv.Itoa(col))
			}
		}
	}

	for len(queue) > 0 {
		str := queue[0]
		queue = queue[1:]
		spl := strings.Split(str, ":")
		row, _ := strconv.Atoi(spl[0])
		col, _ := strconv.Atoi(spl[1])
		val := res[row][col]
		if row + 1 < len(mat) && res[row + 1][col] == 0 && mat[row + 1][col] == 1  {
			res[row + 1][col] = val + 1
			queue = append(queue, strconv.Itoa(row + 1) + ":" + strconv.Itoa(col))
		}
		if row - 1 >= 0 && res[row - 1][col] == 0 && mat[row - 1][col] == 1 {
			res[row - 1][col] = val + 1
			queue = append(queue, strconv.Itoa(row - 1) + ":" + strconv.Itoa(col))
		}
		if col + 1 < len(mat[row]) && res[row][col + 1] == 0 && mat[row][col + 1] == 1 {
			res[row][col + 1] = val + 1
			queue = append(queue, strconv.Itoa(row) + ":" + strconv.Itoa(col + 1))
		}
		if col - 1 >= 0 && res[row][col - 1] == 0 && mat[row][col - 1] == 1 {
			res[row][col - 1] = val + 1
			queue = append(queue, strconv.Itoa(row) + ":" + strconv.Itoa(col - 1))
		}
	}

	return res
}





//Approach 2: TC: O(N * M), SC: O(N * M)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int MAX_VAL = 9999;
        vector<vector<int>> res(mat.size(), vector<int> (mat[0].size(), MAX_VAL));
        for(int row = 0; row < mat.size(); row++) {
            for (int col = 0; col < mat[row].size(); col++) {
                if(mat[row][col] == 1) {
                    int top = (row - 1 >= 0) ? res[row - 1][col] : MAX_VAL;
                    int left = (col - 1 >= 0) ? res[row][col - 1]: MAX_VAL;
                    int minVal = min(top, left);
                    if(minVal != MAX_VAL && res[row][col] > 1 + minVal) {
                        res[row][col] = 1 + minVal;
                    }
                }
                else {
                    res[row][col] = 0;
                }
            }
        }

        for(int row = mat.size() - 1; row >= 0; row--) {
            for (int col = mat[row].size() - 1; col >= 0; col--) {
                if(mat[row][col] == 1) {
                    int bottom = (row + 1 < mat.size()) ? res[row + 1][col] : MAX_VAL;
                    int right = (col + 1 < mat[row].size()) ? res[row][col + 1] : MAX_VAL;
                    int minVal = min(bottom, right);
                    if(minVal != MAX_VAL && res[row][col] > 1 + minVal) {
                        res[row][col] = 1 + minVal;
                    }
                }
                else {
                    res[row][col] = 0;
                }
            }
        }

        return res;
    }
};

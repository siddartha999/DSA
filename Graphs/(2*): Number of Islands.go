/**
* Problem link: https://leetcode.com/problems/number-of-islands/description/
**/

// TC: O(N * N matrix), SC: O(1)
func numIslands(grid [][]byte) int {
    count := 0
    for row := range grid {
        for col := range grid[row] {
            if grid[row][col] == 49 {
                count += 1
                helper(&grid, row, col)
            }
        }
    }
    return count
}

func helper(grid *[][]byte, row int, col int) {
    if row < 0 || col < 0 || row >= len(*grid) || col >= len((*grid)[row]) || (*grid)[row][col] == 48 {
        return
    }
    (*grid)[row][col] = 48
    helper(grid, row - 1, col)
    helper(grid, row, col + 1)
    helper(grid, row + 1, col)
    helper(grid, row, col - 1)
}

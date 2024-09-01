/**
* Problem Link: https://leetcode.com/problems/flood-fill/description/
**/

// TC: O(N * N matrix), SC: O(1), Aux SC: O(N)
func floodFill(image [][]int, sr int, sc int, color int) [][]int {
    helper(&image, sr, sc, color, image[sr][sc])
    return image
}

func helper(image *[][]int, row int, col int, targetColor int, callerColor int) {
    if row < 0 || col < 0 || row >= len(*image) || col >= len((*image)[row]) || (*image)[row][col] != callerColor || 
        (*image)[row][col] == targetColor {
        return
    }

    (*image)[row][col] = targetColor   
    helper(image, row - 1, col, targetColor, callerColor)
    helper(image, row, col + 1, targetColor, callerColor)
    helper(image, row + 1, col, targetColor, callerColor)
    helper(image, row, col - 1, targetColor, callerColor)
}

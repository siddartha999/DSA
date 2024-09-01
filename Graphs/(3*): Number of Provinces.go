/**
* Problem link: https://leetcode.com/problems/number-of-provinces/description/
**/

// Approach 1: BFS. TC: O(N), SC: O(N)
func findCircleNum(isConnected [][]int) int {
	provinceCount := 0
	visited := []int{}

	for vertex := range isConnected {
		if isVisited(&visited, vertex) {
			continue
		}

		provinceCount += 1
		queue := []int{}
		queue = append(queue, vertex)
		for {
			if len(queue) == 0 {
				break
			}

			queueVertex := queue[0]
			queue = queue[1:]
			visited = append(visited, queueVertex)
			for neighborVertex := range isConnected[queueVertex] {
				if isConnected[queueVertex][neighborVertex] == 1 && !isVisited(&visited, neighborVertex) && neighborVertex != queueVertex {
					queue = append(queue, neighborVertex)
				}
			}
		}

	}

	return provinceCount
}

func isVisited(visited *[]int, vertex int) bool {
	for visIdx := range *visited {
		if (*visited)[visIdx] == vertex {
			return true
		}
	}
	return false
}

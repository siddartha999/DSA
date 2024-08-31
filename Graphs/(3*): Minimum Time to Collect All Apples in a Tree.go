/**
* Problem link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
**/

// Approach 1: with a visited set. TC: O(N), SC: O(N)
func minTime(n int, edges [][]int, hasApple []bool) int {
	if n == 1 {
		return 0
	}
	vertexMap := map[int][]int{}
	for index := range edges {
		edge := edges[index]
		vertexMap[edge[0]] = append(vertexMap[edge[0]], edge[1])
		vertexMap[edge[1]] = append(vertexMap[edge[1]], edge[0])
	}
	visited := []int{}
	return helper(0, &vertexMap, &hasApple, visited)
}

func helper(vertex int, vertexMap *map[int][]int, hasApple *[]bool, visited []int) int {
	for idx := range visited {
        if(visited[idx] == vertex) {
            return 0
        } 
    }
	visited = append(visited, vertex)
    
    time := 0

	for idx := range (*vertexMap)[vertex] {
		consider := true
		if consider {
			time += helper((*vertexMap)[vertex][idx], vertexMap, hasApple, visited)
		}
	}

	if vertex == 0 {
		return time
	}

	if time > 0 {
		return time + 2
	}

	if (*hasApple)[vertex] {
		return 2
	}

	return 0
}





// Approach 2: without a Visited set. TC: O(N), SC: O(N)
func minTime(n int, edges [][]int, hasApple []bool) int {
	if n == 1 {
		return 0
	}
	vertexMap := map[int][]int{}
	for index := range edges {
		edge := edges[index]
		vertexMap[edge[0]] = append(vertexMap[edge[0]], edge[1])
		vertexMap[edge[1]] = append(vertexMap[edge[1]], edge[0])
	}
	return helper(0, &vertexMap, &hasApple, -1)
}

func helper(vertex int, vertexMap *map[int][]int, hasApple *[]bool, parentVertex int) int {
	time := 0

	for idx := range (*vertexMap)[vertex] {
		nextVertex := (*vertexMap)[vertex][idx]
		if nextVertex != parentVertex {
			time += helper((*vertexMap)[vertex][idx], vertexMap, hasApple, vertex)
		}
	}

	if vertex == 0 {
		return time
	}

	if time > 0 {
		return time + 2
	}

	if (*hasApple)[vertex] {
		return 2
	}

	return 0
}

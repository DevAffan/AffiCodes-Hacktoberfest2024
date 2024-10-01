import heapq

class Node:
    def __init__(self, position, parent=None):
        self.position = position  # (x, y)
        self.parent = parent
        self.g = 0  # Cost from start to the node
        self.h = 0  # Heuristic cost to the end
        self.f = 0  # Total cost

    def __lt__(self, other):
        return self.f < other.f

def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])  # Manhattan distance

def a_star(start, end, grid):
    open_list = []
    closed_list = set()

    start_node = Node(start)
    end_node = Node(end)

    heapq.heappush(open_list, start_node)

    while open_list:
        current_node = heapq.heappop(open_list)
        closed_list.add(current_node.position)

        if current_node.position == end_node.position:
            path = []
            while current_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1]  # Return reversed path

        neighbors = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # 4 possible movements
        for new_position in neighbors:
            node_position = (current_node.position[0] + new_position[0], 
                             current_node.position[1] + new_position[1])

            if (0 <= node_position[0] < len(grid)) and (0 <= node_position[1] < len(grid[0])):
                if grid[node_position[0]][node_position[1]] == 1 or node_position in closed_list:
                    continue  # Skip walls or already evaluated nodes

                neighbor_node = Node(node_position, current_node)
                neighbor_node.g = current_node.g + 1
                neighbor_node.h = heuristic(node_position, end_node.position)
                neighbor_node.f = neighbor_node.g + neighbor_node.h

                # Check if the neighbor is already in open_list
                if add_to_open(open_list, neighbor_node):
                    heapq.heappush(open_list, neighbor_node)

    return None  # No path found

def add_to_open(open_list, neighbor):
    for node in open_list:
        if neighbor.position == node.position and neighbor.g >= node.g:
            return False
    return True

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 1, 0, 0],
        [0, 0, 0, 0, 0]
    ]

    start = (0, 0)  # Starting point
    end = (4, 4)    # End point
    path = a_star(start, end, grid)

    if path:
        print("Path found:", path)
    else:
        print("No path found.")

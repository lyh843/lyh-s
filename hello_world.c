#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 600
#define MAX_ERRORS 35

// 定义 3D 地图存储
char map[MAX_N][MAX_N][MAX_N];
int n; // 地图大小

// 相邻 6 个方向
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

// 判断是否在地图边界内
bool in_bounds(int x, int y, int z) {
    return x >= 0 && x < n && y >= 0 && y < n && z >= 0 && z < n;
}

// 计算当前点周围的实际地雷数
int count_mines(int x, int y, int z) {
    int count = 0;
    for (int i = 0; i < 6; i++) {
        int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
        if (in_bounds(nx, ny, nz) && map[nx][ny][nz] == '*') {
            count++;
        }
    }
    return count;
}

// 验证地图是否合法
bool validate_map(bool is_question_mine, int *invalid_count, int invalid_coords[MAX_ERRORS][3]) {
    *invalid_count = 0;

    // 遍历整个地图
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                if (map[x][y][z] >= '0' && map[x][y][z] <= '6') {
                    int expected = map[x][y][z] - '0';
                    int actual = count_mines(x, y, z);

                    // 如果当前是 '?'，尝试根据 is_question_mine 设置
                    if (map[x][y][z] == '?') {
                        actual += is_question_mine ? 1 : 0;
                    }

                    // 若不合法记录错误点
                    if (actual != expected) {
                        if (*invalid_count < MAX_ERRORS) {
                            invalid_coords[*invalid_count][0] = x + 1;
                            invalid_coords[*invalid_count][1] = y + 1;
                            invalid_coords[*invalid_count][2] = z + 1;
                        }
                        (*invalid_count)++;
                    }
                }
            }
        }
    }
    return *invalid_count == 0;
}

int main() {
    // 输入地图大小
    scanf("%d", &n);

    // 按字典序读取地图
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                scanf(" %c", &map[x][y][z]);
            }
        }
    }

    // 判断地图是否合法
    int invalid_count;
    int invalid_coords[MAX_ERRORS][3];

    // 假设 '?' 是地雷
    bool valid_as_mine = validate_map(true, &invalid_count, invalid_coords);

    // 假设 '?' 不是地雷
    bool valid_as_empty = validate_map(false, &invalid_count, invalid_coords);

    if (valid_as_mine || valid_as_empty) {
        printf("valid\n");
        printf("%c\n", valid_as_mine ? '*' : '0');
    } else {
        printf("invalid\n");
        for (int i = 0; i < invalid_count; i++) {
            printf("%d %d %d\n", invalid_coords[i][0], invalid_coords[i][1], invalid_coords[i][2]);
        }
    }

    return 0;
}

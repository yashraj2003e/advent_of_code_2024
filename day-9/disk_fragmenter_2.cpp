#include<bits/stdc++.h>
using namespace std;

/*
 *
 * Took few help today !
 *
 */

struct File {
    int id;
    int size;
    int pos;
    int orig_pos;
};

struct FreeSpace {
    int pos;
    int size;
};

int main() {
    clock_t z = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    string disk_map;
    cin >> disk_map;

    vector<File> files;
    vector<FreeSpace> free_spaces;

    int pos = 0;
    int file_id = 0;

    for (size_t i = 0; i < disk_map.size(); i += 2) {
        int file_size = disk_map[i] - '0';
        int free_size = 0;
        if (i + 1 < disk_map.size()) {
            free_size = disk_map[i + 1] - '0';
        }

        if (file_size > 0) {
            File f;
            f.id = file_id++;
            f.size = file_size;
            f.pos = pos;
            f.orig_pos = pos;
            files.push_back(f);
            pos += file_size;
        }
        if (free_size > 0) {
            FreeSpace fs;
            fs.pos = pos;
            fs.size = free_size;
            free_spaces.push_back(fs);
            pos += free_size;
        }
    }

    sort(files.begin(), files.end(), [](const File& a, const File& b) {
        return a.id > b.id;
    });

    for (auto& file : files) {
        int best_pos = -1;
        size_t best_idx = 0;
        for (size_t i = 0; i < free_spaces.size(); ++i) {
            const auto& fs = free_spaces[i];
            if (fs.size >= file.size && fs.pos < file.pos) {
                if (best_pos == -1 || fs.pos < best_pos) {
                    best_pos = fs.pos;
                    best_idx = i;
                }
            }
        }

        if (best_pos != -1) {
            int old_pos = file.pos;
            file.pos = best_pos;

            FreeSpace& fs = free_spaces[best_idx];
            fs.pos += file.size;
            fs.size -= file.size;
            if (fs.size == 0) {
                free_spaces.erase(free_spaces.begin() + best_idx);
            }

            FreeSpace new_fs;
            new_fs.pos = old_pos;
            new_fs.size = file.size;
            free_spaces.push_back(new_fs);
        }
    }

    long long checksum = 0;
    vector<int> disk(pos, -1);

    for (const auto& file : files) {
        for (int i = 0; i < file.size; ++i) {
            disk[file.pos + i] = file.id;
        }
    }

    for (size_t i = 0; i < disk.size(); ++i) {
        if (disk[i] != -1) {
            checksum += static_cast<long long>(i) * disk[i];
        }
    }

    cout << checksum << endl;
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}
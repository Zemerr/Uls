#include "../inc/header.h"

char **mx_files_in_dir(char *dir_name, char trig) {
	//запис файлів в директорії в масив і вивід без флагів;
	DIR *dirp = opendir(dir_name);
	struct dirent *entry;
	char **arr = NULL;
	int i = 0;
	int count = 0;

	if (dirp != NULL) {
		entry = readdir(dirp);
		while (entry) {
			if ((*entry).d_name[0] == '.'
				&& ((*entry).d_name[1] != '\0' && (*entry).d_name[1] != '.')
				&& trig == 'A') {
				count++;
			}
			else if (trig == 'a') {
				count++;
			}
			else if ((*entry).d_name[0] != '.') {
				count++;
			}
			entry = readdir(dirp);
		}
		closedir(dirp);
		if (count == 0) {
			return NULL;
		}
		dirp = opendir(dir_name);
		arr = (char **)malloc(sizeof(char *) * (count + 1));
		entry = readdir(dirp);
			while (entry) {
				if ((*entry).d_name[0] == '.'
					&& ((*entry).d_name[1] != '\0' && (*entry).d_name[1] != '.')
					&& trig == 'A') {
					arr[i] = mx_strdup((*entry).d_name);
					i++;
				}
				else if (trig == 'a') {
					arr[i] = mx_strdup((*entry).d_name);
					i++;
				}
				else if ((*entry).d_name[0] != '.') {
					arr[i] = mx_strdup((*entry).d_name);
					i++;
				}
				entry = readdir(dirp);
			}
			arr[count] = NULL;
			closedir(dirp);
			//тут сортування за алфавітом і вивід в колонках;
			mx_bubble_sort(arr, count);
			// mx_print_cols(arr, count);
	}
	return arr;
}

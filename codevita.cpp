#include < iostream>
#include < vector>
#include < queue>
using namespace std;

int find_min_clicks(int N, vector>& pages, int start, int end) {
	vector visited(N + 1, false);
	queue> q;
	q.push({start, 0});

	while (!q.empty()) {
    	int current_page = q.front().first;
    	int clicks = q.front().second;
    	q.pop();
    	visited[current_page] = true;

    	if (current_page == end) {
        	return clicks;
    	}

    	for (int linked_page : pages[current_page]) {
        	if (!visited[linked_page]) {
            	q.push({linked_page, clicks + 1});
        	}
    	}
	}

	return -1;
}

int main() {
	int N;
	cin >> N;
	vector> pages(N + 1);

	for (int i = 1; i <= N; i++) {
    	int num_links;
    	cin >> num_links;
    	pages[i].resize(num_links);

    	for (int j = 0; j < num_links; j++) {
        	cin >> pages[i][j];
    	}
	}

	int start, end;
	cin >> start >> end;

	int result = find_min_clicks(N, pages, start, end);
	cout << result << endl;

	return 0;
}

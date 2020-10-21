#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;

template <typename C>
struct Edge
{
	int to;
    int cp;
    C cap;

	Edge() {}
	Edge(int pt, C pcap, int pcp) : to(pt), cap(pcap), cp(pcp) { }
};

template <typename C>
class FlowGraph {
using VE = vector <Edge<C>>;
using VVE = vector <VE>;
const C INF = 10000000;
    VVE adja;
    int src;
    int sink;
    int V;
    VI dist;
    VI num;
public:
    FlowGraph (int pv) : V(pv) {
        adja = VVE(pv);
        dist = VI(pv);
        num = VI(pv+1); // can be num[V]
    }

    void addEdge(int f, int t, C c) {
        adja[f].push_back( Edge(t, c, adja[t].size()) );
        adja[t].push_back( Edge(f, 0, adja[f].size()-1) );
    }

    C aug(int now, C leftCap) {
        if(now == sink) {
            return leftCap;
        }

        C remainCap = leftCap;
        int minDist = V;

        for(int i = 0; i < adja[now].size(); i++) {
            int nextv = adja[now][i].to;

            if(adja[now][i].cap > 0 && dist[now] == dist[nextv]+1) {
                C flow = aug(nextv, min(remainCap, adja[now][i].cap));
                adja[now][i].cap -= flow;
                remainCap -= flow;
                adja[nextv][ adja[now][i].cp ].cap += flow;

                if (dist[src] == V || remainCap == 0) {
                    return leftCap-remainCap;
                }
            }
        }

        if(dist[src] == V) {
            return leftCap-remainCap;
        }

        if(remainCap == leftCap) {
            for(int i = 0; i < adja[now].size(); i++) {
                if(adja[now][i].cap) {
                    minDist = min(minDist, dist[ adja[now][i].to ]+1);
                }
            }

            if(--num[ dist[now] ]) {
                ++num[ dist[now] = minDist ];
            }
            else {
                dist[src] = V;
            }
        }
        return leftCap-remainCap;
    }

    C flow(int psrc, int psink) {
        C ret = 0;
        src = psrc;
        sink = psink;

        fill(dist.begin(), dist.end(), 0);
        fill(num.begin(), num.end(), 0);
        num[src] = V;

        while (dist[src] < V) {
            ret += aug(src, INF);
        }

        return ret;
    }
};

int main() {
    int N;
    int M;

    scanf("%d%d", &N, &M);

    VVI edges(M);
    int low = 0;
    int up = M-1;

    for (int i = 0; i < M; ++i) {
        int f;
        int t;
        int w;

        scanf("%d%d%d", &f, &t, &w);
        edges[i] = {w, f, t};
    }

    sort(edges.begin(), edges.end());

    int ans = -1;

    while (low <= up) {
        int midIdx = (low+up) / 2;
        int mid = edges[midIdx][0];
        int src = 0;
        int sink = 2*N+1;
        FlowGraph<int> bg(sink+1);

        for (int i = 1; i <= N; ++i) {
            bg.addEdge(src, i, 1);
            bg.addEdge(i+N, sink, 1);
        }

        for (int i = 0; i < M; ++i) {
            if (edges[i][0] <= mid) {
                bg.addEdge(edges[i][1], edges[i][2]+N, 1);
            } else {
                break;
            }
        }

        if (bg.flow(src, sink) == N) {
            up = midIdx-1;
            ans = mid;
        } else {
            low = midIdx+1;
        }
    }

    cout << ans << endl;

    return 0;
}
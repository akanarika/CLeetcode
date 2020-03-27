class Vector2D {
private:
    int c = -1;
    int nc = 0;
    vector<vector<int>>::iterator r, nr, vend;
public:
    Vector2D(vector<vector<int>>& v) {
        r = v.begin();
        vend = v.end();
    }
    
    int next() {
        if (hasNext()) {
            r = nr;
            c = nc;
            return (*r)[c];
        }
        return 0;
    }
    
    bool hasNext() {
        nc = c + 1;
        nr = r;
        while (nr != vend && nc == (*nr).size() ) {
            nr++;
            nc = 0;
        }
        return !(nr == vend);
    }
};

/**
class Vector2D {
private:
    int r, c;
    int nr, nc;
    vector<vector<int>> _v;
public:
    Vector2D(vector<vector<int>>& v) {
        r = 0;
        c = -1;
        nr = 0;
        nc = 0;
        _v = v;
    }
    
    int next() {
        if (hasNext()) {
            r = nr;
            c = nc;
            return _v[r][c];
        }
        return 0;
    }
    
    bool hasNext() {
        if (r < _v.size() && c + 1 < _v[r].size()) {
            nc = c + 1;
            nr = r;
            return true;
        }
        nr = r + 1;
        nc = 0;
        while ((nr < _v.size()) && (_v[nr].size() == 0)) {
            nr++;
            nc = 0;
        }
        if (nr >= _v.size()) return false;
        return true;
    }
};
**/

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
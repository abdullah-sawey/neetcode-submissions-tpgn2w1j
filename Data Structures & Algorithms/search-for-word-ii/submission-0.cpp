
//o(mn *3^l)  l: length of longest word

class TrieNode
{
    public:
    unordered_map<char , TrieNode*>child;
    bool word_;
};

class Solution {
public:
    TrieNode root;
    unordered_set<string> res;
    vector<vector<bool>> vist;
    void addword(string word)
    {
        TrieNode *curr = &root;
        for(char c : word)
        {
            if(curr->child.count(c)==0)
            {
                curr->child[c] = new TrieNode();
            }
            curr = curr->child[c];
        }
        curr->word_ =true;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        for(string  word : words)
        {
            addword(word);
        }  
        int Row = board.size(), Col = board[0].size();
        vist =vector<vector<bool>>(Row,vector<bool>(Col,false)); 
        for(int r =0 ; r<Row; r++)
        {
            for(int c=0; c<Col;c++)
            {
                dfs(board ,r,c, "", &root);
            }
        }

        return vector<string>(res.begin(),res.end());
    }


    void dfs(vector<vector<char>>& board,int r , int c , string word ,TrieNode* node)
    {
        int Row = board.size(), Col = board[0].size();
        if( (r<0) || (r>= Row) || (c<0) ||(c>=Col) || vist[r][c] ||
            !node->child.count(board[r][c]) )
        {
            return ;
        }

        vist[r][c] =true;
        node =node->child[board[r][c]];
        word += board[r][c];
        if(node->word_)  // it will not be true , expet shifting last char of word.
        {
            res.insert(word);
        }
        dfs(board ,r+1,c, word, node);
        dfs(board ,r-1,c, word, node);
        dfs(board ,r,c+1, word, node);
        dfs(board ,r,c - 1, word, node);
        vist[r][c] =false;
    }
};

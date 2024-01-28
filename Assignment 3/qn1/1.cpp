#include<bits/stdc++.h>
using namespace std;
#define ll long long

//this function performs matrix addition and returns resultant matrix
vector<vector<ll>> add(const vector<vector<ll>>& A, const vector<vector<ll>>& B){
    ll n=A.size();
    vector<vector<ll>> result(n, vector<ll>(n));
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            result[i][j]=A[i][j]+B[i][j];
        }
    }
    return result;
    //time complexity is O(n^2) due to the nested loops
}

//matrix multiplication using divide and conquer algorithm
vector<vector<ll>> multiply_matrix(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    ll n=A.size();
    if(n == 1){
        //base case: 1x1 matrix simple multiplication
        return {{A[0][0]*B[0][0]}};
    }

    ll mid=n / 2;

    //Dividing each A and B llo 4 matrices of mid x mid dimensions

    vector<vector<ll>> A11(mid, vector<ll>(mid));
    vector<vector<ll>> A12(mid, vector<ll>(mid));
    vector<vector<ll>> A21(mid, vector<ll>(mid));
    vector<vector<ll>> A22(mid, vector<ll>(mid));
    for(ll i=0; i<mid; i++) {
        for(ll j=0; j<mid; j++) {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+mid];
            A21[i][j]=A[i+mid][j];
            A22[i][j]=A[i+mid][j+mid];
        }
    }

    vector<vector<ll>> B11(mid, vector<ll>(mid));
    vector<vector<ll>> B12(mid, vector<ll>(mid));
    vector<vector<ll>> B21(mid, vector<ll>(mid));
    vector<vector<ll>> B22(mid, vector<ll>(mid));
    for(ll i=0; i<mid; i++) {
        for(ll j=0; j<mid; j++) {
            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+mid];
            B21[i][j]=B[i+mid][j];
            B22[i][j]=B[i+mid][j+mid];
        }
    }

    // recursive matrix multiplication
    vector<vector<ll>> C11=add(multiply_matrix(A11, B11), multiply_matrix(A12, B21));
    vector<vector<ll>> C12=add(multiply_matrix(A11, B12), multiply_matrix(A12, B22));
    vector<vector<ll>> C21=add(multiply_matrix(A21, B11), multiply_matrix(A22, B21));
    vector<vector<ll>> C22=add(multiply_matrix(A21, B12), multiply_matrix(A22, B22));

    vector<vector<ll>> result(n, vector<ll>(n));
    for(ll i=0; i<mid; i++) {
        for(ll j=0; j<mid; j++) {
            result[i][j]=C11[i][j];
            result[i][j+mid]=C12[i][j];
            result[i+mid][j]=C21[i][j];
            result[i+mid][j+mid]=C22[i][j];
        }
    }
    return result; 
}




int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll n;cin>>n;
    //rounding up n to its nearest power of 2
    ll size=__bit_ceil(n); 
    //all the extra cells are filled with 0s
    vector<vector<ll>> A(size,vector<ll>(size));
    vector<vector<ll>> B(size,vector<ll>(size));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>A[i][j]; 
        }
    } 
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>B[i][j]; 
        }
    } 
    vector<vector<ll>> C=multiply_matrix(A,B); 
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout<<C[i][j]<<" "; 
        }
        cout<<endl;
    }

    //Time complexity = O(N^3)


    return 0;
}
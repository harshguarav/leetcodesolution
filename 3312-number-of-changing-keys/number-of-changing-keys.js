/**
 * @param {string} s
 * @return {number}
 */
var countKeyChanges = function(s) {
    let t=s.toLowerCase();
    let count=0;
    for(let i=1;i<=t.length-1;i++){
        if(t[i]!=t[i-1]){
            count++;
        }
    }
    return count;
    
};
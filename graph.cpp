# cycle detection:
   -->using cycle wala bfs : when we pop queue let 'a' another element 'a' at the same level then it is forming cycle, isse bipartite bhi nikal skte h
      basically m issme intrested hu k mere level pe aane wale log sare unvisited h ya nhi
      -->isme queue se nikalne k baad true mark krte h
   
# normally bfs m queue m dalne se phle mark krte h (iski space complexity acchi hoti h)
   basically isme bs m sare unvisited to traverse krna chahta hu


# bipartite mtlb alternate colouring possible h

                                 Graph
                                 /    \
                                /       \
                           cyclic     non cyclic
                            / \             \
                      odd /     \ even       \
                        /         \            \
                non bipartite    bipartite   bipartite
                
algorithm: har ek node alternate colouring do. iska mtlb hr level ek type k colour se
           coloured hoga. isi process m kisi instant pr aisa dikhta h ki jo node abhi
           pop out hua h wo phle se hi colored (visited) h iska mtlb ye h ki isme cycle h.
  
           cycle to detect ho gya pr ye kase pta chalega k ye even cycle h ya odd cycle h.
  
           to iske liye dekhenge k iska color ar previous wale ka colour same h to koi conflict nhi h even
           length h. nhi to cycle odd length ka h.
   
           
 directed graph(one ended -> ):
     topological sort sirf directed graph m hi use kr skte h ya fir asa bol skte h k
     hm jb kisi dependencies ko graphically repersent krte h to kis order excute kr skte h
     wo topological sort se pta chalta h.
     
  # topological order kaise nikalte h:
        simple dfs se topological order nikal skte h bs last m element ko store kr lo
        lkn dikkat ye h ki ye bta nhi pata k jo order aya h wo valid k nhi i mean graph
        m cycle present h to uska topological order nikal nhi skte. pr dfs to nikal dega 
        fir verify krte rho.
   ->iska soln h kahns algo   
  # kahns algo:      
               indigree(mere pe kitne depend kr rhe h) ka concept h. isme bfs indigre k base pe lgaenge
               ar hmesha ye dekhenge k agr mere pe ek bnda depend h to m next succesor bn skta hu to use 
               queue k andr daal do.
                  
               que ka har "L" level ye bolta h k hm sb apna kaam "Lth" number se start kr skte h kuki hmari dependencies 
               khtm ho gyi h
               
              result analysis: 
              jb jb que se nikal rhe to use tmne vector m daala h as your ans. tmhra ans correct h i mean tumhare schedule 
              graph m koi cycle nhi h to ans m sare numbers present honnge 1-N.
              agr scheduling possible nhi h to hmara kahns algo bich m ruk gya hoga ar ans wale vector m kchh element 
              km honge. to ye pta chal jayega k cycle h
                 




















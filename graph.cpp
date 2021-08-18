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
   
           
           
                          




















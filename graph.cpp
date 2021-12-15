# go to the leetcode question of that algorithm for detail of any algorithm. 

# cycle detection:
   -->using cycle wala bfs : when we pop queue let 'a' another element 'a' at the same level then it is forming cycle, isse bipartite bhi nikal skte h
      basically m issme intrested hu k mere level pe aane wale log sare unvisited h ya nhi
      -->isme queue se nikalne k baad true mark krte h
      
      -->ye sirf undirected graph k lie bola h baki directed graph k liye hm kahn's algo ar dfs use krte h.
   
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
        
 # hameltonian cycle: 
        ek source se start kr k m sare node ko visit kr leta hu kisi node ko do baar visit nhi krta to 
        jo last wala node h agr us se koi ek branch bhi source ko touch krta h to ye hemoltonian cycle h
        ek se jyada cycle exist kr skta h.
 # hameltonian path: 
           us cycle ka path print kr do 
  # topological order kaise nikalte h:
        simple dfs se topological order nikal skte h bs last m element ko store kr lo
        lkn dikkat ye h ki ye bta nhi pata k jo order aya h wo valid k nhi i mean graph
        m cycle present h to uska topological order nikal nhi skte. pr dfs to nikal dega 
        fir verify krte rho.
   ->iska soln h kahns algo   
  # kahns algo:  (for directed graph)    
               indigree(mere pe kitne depend kr rhe h) ka concept h. isme bfs indigre k base pe lgaenge
               ar hmesha ye dekhenge k agr mere pe ek bnda depend h to m next succesor bn skta hu to use 
               queue k andr daal do.
                  
               que ka har "L" level ye bolta h k hm sb apna kaam "Lth" number se start kr skte h kuki hmari dependencies 
               khtm ho gyi h
               
              result analysis: 
              jb jb que se nikal rhe to use tmne vector m daala h as your ans. tmhra ans correct h i mean tumhare schedule 
              graph m koi cycle nhi h to ans m sare numbers present honnge 1-N.
              agr scheduling possible nhi h to hmara kahns algo bich m ruk gya hoga ar ans wale vector m kchh element 
              km honge. to ye pta chal jayega k cycle h.
                 
# directed graph m cycle detect krna(khans algo wala kaam dfs se kase krna h):
             ye chij to bfs se easily ho rha h jsa upar likha h pr kya hm dfs se ye chij bta skte h?
             ha dfs se bta skte h k hmara sheduled graph m koi cycle h ya nhi bs thoda sa modification kr k "topological order by dfs"
             kon kon se element ek time pr excute kre ja skte h isko pta lgane k lie last m store kra lo recursion k basically post order m.
             dfs se agr pta lagana h k cycles exist krti h ya nhi to bs return type m thodi changes krni pd jayegi 0,1,2 state ho jayega fir 
             hm find kr skte h
                 
# Union find in graphs: jo graph dia hua h wo sb connected rhe (kisi condition m like km se km weight ho) ar unk bich m cycle na ho basically 
            spanning tree use hm union find method se solve krte h
            2nd interpertation: ek grp of number m se m koi bhi number select kru mjhe ek hi number mile ar wo number un sb m se special hongi
# minimum spanning tree:
            m agr sort kr du edges ko ar union find lgauo to sbse jyada weight wala edge sbse last m ayega ar ye possible h k wo cycle bna rha ho is
            case m wo add nhi hoga so resulting graph bnne wala h wo hmara minimum spanning tree hoga.
            
# dijikstra algo  (bfs cycle wla)
                priority queue se element weight so far k base pe nikalte h
                dijikstra ar mst m diff? 
                mst m heavisest weight wala edge nhi hota pr dijikstra source dependent h mtlb m jha se start kr rha hu us jgh se khada ho k dekhta hu 
                graph m jitne bhi node h sb connected honge ar path untk phuchne ka min hoga.
 
               negative cycle k liye kaam nhi krta
   
//leetcode 787   
# Bellman Ford algo (dijkstra wala kaam,pr negative m bhi use kr skte h)
                dynamic approch follow krte h
                ek prev arr bnao jo prev state store kr k rkhta h ,initially sbko inf set kr do
                hr bar ek curr arr m copy kro ar usme nod ko relax kro    
                hme edges ko relax krna h mtlb check kro k if( wsf + w[currNod] < w[nxtNod]) to update kr do
                agr relax kisi instant pe nhi hota ek bhi node to mtlb abhi jo hmare curr array m h whi best possible ans h
                agr graph m asa koi loop jiska sum negative h to is case m ye  kaam nhi krta pr bta jrr dega k mera o/p valid nhi h
                no. of edges n-1 ,agr hm n bar iterate krte h ar koi node update ho rha h mtlb ek negative loop ka cycle present h ar iska ans nikalna possible nhi h
                
# kruskal algo : (union find sorted order m)
                 graph bnane ki jrrt nhi
                 ek mst jisme heavy wala edge removed hota h
              
# prims algo : (bfs)
              graph bnane ki jrrt h
              ek mst isme priority que use hota h bilkul dijkstra jase
              dijkstra m weight so far (wsf) jata h jbki prims m weight hi jata h

prims and kruskal dono mst bnate h.prims dense graph k andr achha perform krta h kruskal sparsh graph k andr achha perform krta h
prims kruskal interchangebly use kr skte h.

                   
In a graph, a vertex is called an articulation point if removing it and all the edges associated with it results in the increase 
of the number of connected components in the graph.                   
               
#articulation point: isme dfs lgana hota h ar hrek node ko time stamp dena hota h k kb discover hua ar us node ki reach kha tk h
               do blocks h ek jb node visted nhii h
            { 
              dfs call krna h
                    dfs ek point pe end hoga jb aage wala node visited h ya fir uska koi child nhi h
                    agr dfs khtm hua visited node k wjh se to iska mtlb h k visited wala node ka time stamp km hoga ar uska reach bhi powerful(low value) hoga
                    agr wo node ka contact powerfull node se h ar mera contact isi se ho to m bhi powerful ko reach kr skta hu to mne apna reach update kr lia
              low[src]=min(low[src],low[vt])
              
                    waps aate hue m ye dekh rha hu k jo mere vertices h unka reach mjh se ho k ho k gujarta h mtlb m agr discover 4 pe hua ar child ka reach 5 h
                    mtlb koi ar rasta nhi h jisse mere child k pas jaya ja sake to wo mere upar dependent h isliye m apne child k respect m articulation point hu
              if(disc[src]<=low[vt])
              articulationpnt++
              
            }
dusra jb node visited h
{
                     ye wo case h jisme mera child visited hoga usko low stamp mila hoga to is case m is chij ki gurantee le skta hu k source wale ki reach atleast wha tk to h jb
                     uska child discover hua tha is case m hme disc[timestapmp] se uske low ko update krna hoga.
                     
      low[sr]=min(low[src],disc[vt])               
}

#      source node ko explictly treat krna pdega abhi tk algo se ye pta chalta h k jitne bhi articulation kisi ek point pr h agr usko hta du to usse ek jyada number of components 
       bnenge lkn ye chij source node k liye shi nhi h
       
#      sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });
   


//924. Minimize Malware Spread
phle iska node wala graph bnao fir sbka population ar no. of infected in that population nikalo;
population isliye qk question ne higher population bchane ko bola h ar infected is liye q k agr ek se jyada infected h to use bcha nhi skte











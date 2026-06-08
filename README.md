# selecao-supp-em-C

A supplier selection algorithm built in C, based on three core pillars, developed during algorithm classes as part of my engineering coursework

This decision-making algorithm was developed for computer programming and algorithm classes in an engineering course thinking about a classic logistics and supply chain problem. 
The system evaluates and ranks suppliers based on weighted priorities defined by the user, analyzing three core pillars: price, delivery time efficiency, and quality scores ranging from 1 to 5. 
The project addresses a critical real-world challenge: reducing human subjectivity and favoritism in supply procurement processes through a data-based approach. 
By allowing strategic customization, the system can adapt to many scenarios where quality must override cost, or standard operations that prioritize budget and deadlines.

Technically, it stores supplier metrics in organized arrays and applies a dynamic weighting logic based on primary and secondary priorities chosen by the user. 
To ensure an unbiased comparison, the algorithm normalizes distinct metrics, such as days and currency, into a standard 0 to 10 scale before calculating a final weighted average. 
Finally, a selection sort loop reorganizes the entire dataset simultaneously to maintain data integrity, then it allows real-time recalculations without system restarts.

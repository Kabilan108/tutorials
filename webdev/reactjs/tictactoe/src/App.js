import { useState } from 'react';


function Square({ value, onSquareClick }) {
    return (
        <button className="square" onClick={onSquareClick}>
            {value}
        </button>
    );
}

function Board() {
    // state variables in parent component are passed to child components
    const [xIsNext, setXIsNext] = useState(true) // track 'X' or 'O'
    // each time a player moves, flip xIsNext
    const [squares, setSquares] = useState( Array(9).fill(null) )

    // event handler for child component
    function handleClick(i) {
        // 
        if (squares[i] != null) {
            return
        }

        // create an immutable copy of the state variable
        //   no direct mutation of state variables
        const nextSquares = squares.slice()
        
        if (xIsNext) {
            nextSquares[i] = 'X'
        } else {
            nextSquares[i] = 'O'
        }

        setSquares(nextSquares)
        setXIsNext(!xIsNext)
    }

    return (
        <>
            {/* the mapFn to Array.from takes `element` and `index` */}
            {Array.from({ length: 3 }, (_, i) => (
                <div key={i} className="board-row">
                    {Array.from({ length: 3 }, (_, j) => {
                        let k = i * 3 + j;
                        return (
                            // create arrow function to pass index to event handler
                            <Square 
                                value={squares[k]} 
                                onSquareClick={() => handleClick(k)} 
                            />
                        );
                    })}
                </div>
            ))}
        </>
    );
}

export default Board;

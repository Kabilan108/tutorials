function Square({ value }) {    
    function handleClick() {
        console.log('clicked');
    }

    return (
        <button 
            className="square"
            onClick={handleClick}
        >
            {value}
        </button>
    );
}

export default function Board() {
    return (
        <>
            {/* the mapFn to Array.from takes `element` and `index` */}
            {Array.from({ length: 3 }, (_, i) => (
                <div key={i} className="board-row">
                    {Array.from({ length: 3 }, (_, j) => {
                        let k = i * 3 + j + 1;
                        return <Square key={k} value={k} />
                    })}
                </div>
            ))}
        </>
    );
}

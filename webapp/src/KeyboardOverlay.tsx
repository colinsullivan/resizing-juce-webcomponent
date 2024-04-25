import React, { useEffect } from "react";

const style: React.CSSProperties = {
  position: "absolute",
  top: 0,
  left: 0,
  width: "100%",
  height: "100%",

  color: "gray",
};

interface KeyEvent {
    time: number;
    key: string;
}

const KeyboardOverlay = () => {
    const [lastKeyEvent, setLastKeyEvent] = React.useState<KeyEvent | null>(null);
  useEffect(() => {
    const handleKeyDown = (event: KeyboardEvent) => {
        setLastKeyEvent({time: Date.now(), key: event.key});
    };

    window.addEventListener("keydown", handleKeyDown);

    return () => {
      window.removeEventListener("keydown", handleKeyDown);
    };
  });
  return (
    <div style={style}>
    <h2>Last key event:</h2>
      <div>
          {lastKeyEvent ? `Key: ${lastKeyEvent.key}, Time: ${lastKeyEvent.time}` : "No key event yet"}
      </div>
    </div>
  );
};

export default KeyboardOverlay;

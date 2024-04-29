//Declaring variables for the board, score, and parameters for whether the game is over or not.
var board;
var score = 0;
var rows = 4;
var columns = 4;

window.onload = function () {
  setGame();
};

//SETTING UP THE BOARD AT START OF GAME
function setGame() {
  //Setting up the board array as 4 arrays of 0s
  board = [
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
    [0, 0, 0, 0],
  ];

  //Displaying the block on the website
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < columns; c++) {
      var block = document.createElement("div");
      block.id = r.toString() + "-" + c.toString();
      var num = board[r][c];
      updateBlock(block, num);
      document.getElementById("board").append(block);
    }
  }

  //Generating two random block for the game to start
  setTwo();
  setTwo();
}

//Going through all tiles, then checking to see if the value is a 0 before adding a new block there
function updateBlock(block, num) {
  //Sets the block to 0 by default;
  block.innerText = "";
  block.classList.value = "";
  block.classList.add("block");

  //condition to have a block if it is not 0
  if (num > 0) {
    block.innerText = num.toString();
    if (num <= 4096) {
      block.classList.add("x" + num.toString());
    } else {
      block.classList.add("x8192");
    }
  }
}

//Arrow key inputs
document.addEventListener("keyup", (input) => {
  if (input.code == "ArrowLeft") {
    slideLeft();
    genblock();
  } else if (input.code == "ArrowRight") {
    slideRight();
    genblock();
  } else if (input.code == "ArrowUp") {
    slideUp();
    genblock();
  } else if (input.code == "ArrowDown") {
    slideDown();
    genblock();
  }
  //updating the score value on browser
  document.getElementById("score").innerText = score;
});

// WASD inputs
document.addEventListener("keypress", (e) => {
  if (e.code == "KeyA") {
    slideLeft();
    setTwo();
  } else if (e.code == "KeyD") {
    slideRight();
    setTwo();
  } else if (e.code == "KeyW") {
    slideUp();
    setTwo();
  } else if (e.code == "KeyS") {
    slideDown();
    setTwo();
  }
  document.getElementById("score").innerText = score;
});

//Sliding functions

function slideLeft() {
  for (let i = 0; i < rows; i++) {
    for (let j = 3; j > 0; j--) {
      if (board[i][j] != 0 && board[i][j - 1] == 0) {
        board[i][j - 1] = board[i][j];
        board[i][j] = 0;
      } else if (board[i][j] != 0 && board[i][j - 1] == board[i][j]) {
        board[i][j - 1] = board[i][j] * 2;
        score += board[i][j] * 2;
        board[i][j] = 0;
      }
    }
  }
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < columns; j++) {
      if (board[i][j] != 0 && board[i][j - 1] == 0) {
        board[i][j - 1] = board[i][j];
        board[i][j] = 0;
      }
    }
  }
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < columns; j++) {
      let block = document.getElementById(i.toString() + "-" + j.toString());
      let num = board[i][j];
      updateBlock(block, num);
    }
  }
}

function slideRight() {
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < columns; j++) {
      if (board[i][j] != 0 && board[i][j + 1] == 0) {
        board[i][j + 1] = board[i][j];
        board[i][j] = 0;
      } else if (board[i][j + 1] == board[i][j]) {
        board[i][j + 1] = board[i][j] * 2;
        score += board[i][j] * 2;
        board[i][j] = 0;
      }
    }
  }
  for (let i = 0; i < 4; i++) {
    for (let j = 0; j < columns; j++) {
      if (board[i][j] != 0 && board[i][j + 1] == 0) {
        board[i][j + 1] = board[i][j];
        board[i][j] = 0;
      }
    }
  }
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < columns; j++) {
      let block = document.getElementById(i.toString() + "-" + j.toString());
      let num = board[i][j];
      updateBlock(block, num);
    }
  }
}

function slideUp() {
  for (let i = 3; i > 0; i--) {
    for (let j = 0; j < 4; j++) {
      if (board[i][j] != 0 && board[i - 1][j] == 0) {
        board[i - 1][j] = board[i][j];
        board[i][j] = 0;
      } else if (board[i - 1][j] == board[i][j]) {
        board[i - 1][j] = board[i][j] * 2;
        score += board[i][j] * 2;
        board[i][j] = 0;
      }
    }
  }
  for (let i = 3; i > 0; i--) {
    for (let j = 0; j < 4; j++) {
      if (board[i][j] != 0 && board[i - 1][j] == 0) {
        board[i - 1][j] = board[i][j];
        board[i][j] = 0;
      }
    }
  }
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < columns; j++) {
      let block = document.getElementById(i.toString() + "-" + j.toString());
      let num = board[i][j];
      updateBlock(block, num);
    }
  }
}

function slideDown() {
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 4; j++) {
      if (board[i][j] != 0 && board[i + 1][j] == 0) {
        board[i + 1][j] = board[i][j];
        board[i][j] = 0;
      } else if (board[i + 1][j] == board[i][j]) {
        board[i + 1][j] = board[i][j] * 2;
        score += board[i][j] * 2;
        board[i][j] = 0;
      }
    }
  }
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 4; j++) {
      if (board[i][j] != 0 && board[i + 1][j] == 0) {
        board[i + 1][j] = board[i][j];
        board[i][j] = 0;
      }
    }
  }
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < columns; j++) {
      let block = document.getElementById(i.toString() + "-" + j.toString());
      let num = board[i][j];
      updateBlock(block, num);
    }
  }
}

function setTwo() {
  if (!isFull()) {
    let randomx = Math.floor(Math.random() * 4);
    let randomy = Math.floor(Math.random() * 4);
    while (board[randomx][randomy] !== 0) {
      randomx = Math.floor(Math.random() * 4);
      randomy = Math.floor(Math.random() * 4);
    }
    board[randomx][randomy] = 2;
    let block = document.getElementById(randomx + "-" + randomy);
    block.innerText = "2";
    block.classList.add("x2");
  }
}

function isFull() {
  for (let i = 0; i < 4; i++) {
    for (let j = 0; j < 4; j++) {
      if (board[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}

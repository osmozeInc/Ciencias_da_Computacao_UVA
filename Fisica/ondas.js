const canvas = document.getElementById("onda");
const ctx = canvas.getContext("2d");

// Parâmetros da onda

let t = 0; // tempo

function desenharOnda() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.beginPath();
    const yBase = canvas.height / 2;

    // Parâmetros da onda
    let x = parseFloat(document.getElementById("posicao").value);
    const A = parseFloat(document.getElementById("amplitude").value); // amplitude
    const lambda = parseFloat(document.getElementById("comprimento").value); // comprimento da onda
    const f = parseFloat(document.getElementById("frequencia").value); // frequência
    const k = 2 * Math.PI / lambda; // número de onda
    const w = 2 * Math.PI * f; // frequência angular


    for (x; x < canvas.width; x++) {
        let y = A * Math.sin(k * x - w * t);
        ctx.lineTo(x, yBase + y);
    }

    ctx.strokeStyle = "red";
    ctx.lineWidth = 2;
    ctx.stroke();

  t += 0.0007;
  requestAnimationFrame(desenharOnda);
}

const desenhar = document.querySelector("#desenhar");
desenhar.addEventListener("click", () => desenharOnda());

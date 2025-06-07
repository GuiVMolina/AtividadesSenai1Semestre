async function sendMessage() {
    const chatBox = document.getElementById('chatBox');
    const userInput = document.getElementById('userInput');
    const userMessage = userInput.value;

    if (!userMessage) return;
    const userDiv = document.createElement('div');
    userDiv.className = 'user-message message';
    userDiv.textContent = userMessage;
    chatBox.appendChild(userDiv);
    userInput.value = '';
    chatBox.scrollTop = chatBox.scrollHeight;

    // Configuração dos parâmetros
    const endpoint = "guilhermemolinagpt-resource.openai.azure.com";
    const apiKey = "7rzYG2cGoz4LNYp4dHATu5QqcTW5AeQFH3j6ksiQLSUTbdVEtNlMJQQJ99BFACHYHv6XJ3w3AAAAACOGZNM5";
    const deploymentId = "gpt-4o";
    const apiVersion = "2024-05-01-preview";
    const url = `https://${endpoint}/openai/deployments/${deploymentId}/chat/completions?api-version=${apiVersion}`;
    const data = {
        "messages": [{ role: "user", content: userMessage }],
        "max_tokens": 100,
        "temperature": 0.7
    };
    const headers = {
        "Content-Type": "application/json",
        "api-key": apiKey
    };

    try {
        const response = await fetch(url, {
            method: 'POST',
            headers: headers,
            body: JSON.stringify(data)
        });

        if (response.ok) {
            const result = await response.json();
            const botMessage = result.choices?.[0]?.message?.content || "Resposta vazia da API.";

            const botDiv = document.createElement('div');
            botDiv.className = 'bot-message message';
            botDiv.textContent = botMessage;
            chatBox.appendChild(botDiv);
            chatBox.scrollTop = chatBox.scrollHeight;
        } else {
            console.error('Erro na requisição: ', response.status, response.statusText);
            const botDiv = document.createElement('div');
            botDiv.className = 'bot-message message';
            botDiv.textContent = "Erro ao se comunicar com o serviço";
            chatBox.appendChild(botDiv);
        }
    } catch (error) {
        console.error('Erro: ', error);
        const botDiv = document.createElement('div');
        botDiv.className = 'bot-message message';
        botDiv.textContent = "Erro ao se comunicar com o serviço";
        chatBox.appendChild(botDiv);
    }
}

// Envio com Enter
document.addEventListener('DOMContentLoaded', () => {
    const userInput = document.getElementById('userInput');
    if (userInput) {
        userInput.addEventListener('keydown', function (e) {
            if (e.key === 'Enter') {
                sendMessage();
            }
        });
    }
});
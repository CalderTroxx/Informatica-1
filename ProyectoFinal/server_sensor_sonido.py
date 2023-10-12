from flask import Flask, request

app = Flask(__name__)

@app.route('/guardar_datos.php', methods=['GET'])
def guardar_datos():
    valor = request.args.get('valor')
    with open('datos_sonido.txt', 'a') as f:
        f.write(valor + '\n')
    return 'Datos recibidos y guardados en datos_sonido.txt'

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=80)

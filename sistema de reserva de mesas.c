#include <stdio.h>
#include <string.h>
#define MAX_RESERVAS 100

typedef struct {
    char nomeCliente[50];
    char data[11]; // Formato: DD/MM/AAAA
    char horario[6]; // Formato: HH:MM
    int mesa;
} Reserva;

Reserva reservas[MAX_RESERVAS];
int totalReservas = 0;

void adicionarReserva() {
    if (totalReservas >= MAX_RESERVAS) {
        printf("\nLimite de reservas alcançado!\n");
        return;
    }

    Reserva novaReserva;

    printf("\nNome do cliente: ");
	scanf(" %[^\n]", novaReserva.nomeCliente);

    printf("Data (DD/MM/AAAA): ");
    scanf(" %s", novaReserva.data);

    printf("Horário (HH:MM): ");
    scanf(" %s", novaReserva.horario);

    printf("Número da mesa: ");
    scanf(" %d", &novaReserva.mesa);

    // Verificar disponibilidade
    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].mesa == novaReserva.mesa &&
            strcmp(reservas[i].data, novaReserva.data) == 0 &&
            strcmp(reservas[i].horario, novaReserva.horario) == 0) {
            printf("\nMesa ja reservada para esta data e horario.\n");
            return;
        }
    }

    reservas[totalReservas++] = novaReserva;
    printf("\nReserva confirmada para %s na mesa %d em %s as %s.\n", novaReserva.nomeCliente, novaReserva.mesa, novaReserva.data, novaReserva.horario);
}

void listarReservas() {
    if (totalReservas == 0) {
        printf("\nNenhuma reserva registrada.\n");
        return;
    }

    printf("\nReservas atuais:\n");
    for (int i = 0; i < totalReservas; i++) {
        printf("%d. Cliente: %s | Data: %s | Horario: %s | Mesa: %d\n", i + 1, reservas[i].nomeCliente, reservas[i].data, reservas[i].horario, reservas[i].mesa);
    }
}

void menu() {
    int opcao;

    do {
        printf("\n--- Sistema de Reserva de Mesas ---\n");
        printf("1. Adicionar Reserva\n");
        printf("2. Listar Reservas\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                adicionarReserva();
                break;
            case 2:
                listarReservas();
                break;
            case 3:
                printf("\nSaindo do sistema. Ate mais!\n");
                break;
            default:
                printf("\nOpção invalida. Tente novamente.\n");
        }
    } while (opcao != 3);
}

int main() {
    menu();
    return 0;
}

